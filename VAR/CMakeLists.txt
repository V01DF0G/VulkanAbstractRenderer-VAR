set(PROJECT_NAME VAR)

################################################################################
# Source groups
################################################################################
set(Vendor__glm__glm
    "Vendor/glm/glm/common.hpp"
    "Vendor/glm/glm/exponential.hpp"
    "Vendor/glm/glm/ext.hpp"
    "Vendor/glm/glm/fwd.hpp"
    "Vendor/glm/glm/geometric.hpp"
    "Vendor/glm/glm/glm.hpp"
    "Vendor/glm/glm/integer.hpp"
    "Vendor/glm/glm/mat2x2.hpp"
    "Vendor/glm/glm/mat2x3.hpp"
    "Vendor/glm/glm/mat2x4.hpp"
    "Vendor/glm/glm/mat3x2.hpp"
    "Vendor/glm/glm/mat3x3.hpp"
    "Vendor/glm/glm/mat3x4.hpp"
    "Vendor/glm/glm/mat4x2.hpp"
    "Vendor/glm/glm/mat4x3.hpp"
    "Vendor/glm/glm/mat4x4.hpp"
    "Vendor/glm/glm/matrix.hpp"
    "Vendor/glm/glm/packing.hpp"
    "Vendor/glm/glm/trigonometric.hpp"
    "Vendor/glm/glm/vec2.hpp"
    "Vendor/glm/glm/vec3.hpp"
    "Vendor/glm/glm/vec4.hpp"
    "Vendor/glm/glm/vector_relational.hpp"
)
source_group("Vendor\\glm\\glm" FILES ${Vendor__glm__glm})

set(Vendor__glm__glm__detail
    "Vendor/glm/glm/detail/_features.hpp"
    "Vendor/glm/glm/detail/_fixes.hpp"
    "Vendor/glm/glm/detail/_noise.hpp"
    "Vendor/glm/glm/detail/_swizzle.hpp"
    "Vendor/glm/glm/detail/_swizzle_func.hpp"
    "Vendor/glm/glm/detail/_vectorize.hpp"
    "Vendor/glm/glm/detail/compute_common.hpp"
    "Vendor/glm/glm/detail/compute_vector_relational.hpp"
    "Vendor/glm/glm/detail/func_common.inl"
    "Vendor/glm/glm/detail/func_common_simd.inl"
    "Vendor/glm/glm/detail/func_exponential.inl"
    "Vendor/glm/glm/detail/func_exponential_simd.inl"
    "Vendor/glm/glm/detail/func_geometric.inl"
    "Vendor/glm/glm/detail/func_geometric_simd.inl"
    "Vendor/glm/glm/detail/func_integer.inl"
    "Vendor/glm/glm/detail/func_integer_simd.inl"
    "Vendor/glm/glm/detail/func_matrix.inl"
    "Vendor/glm/glm/detail/func_matrix_simd.inl"
    "Vendor/glm/glm/detail/func_packing.inl"
    "Vendor/glm/glm/detail/func_packing_simd.inl"
    "Vendor/glm/glm/detail/func_trigonometric.inl"
    "Vendor/glm/glm/detail/func_trigonometric_simd.inl"
    "Vendor/glm/glm/detail/func_vector_relational.inl"
    "Vendor/glm/glm/detail/func_vector_relational_simd.inl"
    "Vendor/glm/glm/detail/qualifier.hpp"
    "Vendor/glm/glm/detail/setup.hpp"
    "Vendor/glm/glm/detail/type_float.hpp"
    "Vendor/glm/glm/detail/type_half.hpp"
    "Vendor/glm/glm/detail/type_half.inl"
    "Vendor/glm/glm/detail/type_mat2x2.hpp"
    "Vendor/glm/glm/detail/type_mat2x2.inl"
    "Vendor/glm/glm/detail/type_mat2x3.hpp"
    "Vendor/glm/glm/detail/type_mat2x3.inl"
    "Vendor/glm/glm/detail/type_mat2x4.hpp"
    "Vendor/glm/glm/detail/type_mat2x4.inl"
    "Vendor/glm/glm/detail/type_mat3x2.hpp"
    "Vendor/glm/glm/detail/type_mat3x2.inl"
    "Vendor/glm/glm/detail/type_mat3x3.hpp"
    "Vendor/glm/glm/detail/type_mat3x3.inl"
    "Vendor/glm/glm/detail/type_mat3x4.hpp"
    "Vendor/glm/glm/detail/type_mat3x4.inl"
    "Vendor/glm/glm/detail/type_mat4x2.hpp"
    "Vendor/glm/glm/detail/type_mat4x2.inl"
    "Vendor/glm/glm/detail/type_mat4x3.hpp"
    "Vendor/glm/glm/detail/type_mat4x3.inl"
    "Vendor/glm/glm/detail/type_mat4x4.hpp"
    "Vendor/glm/glm/detail/type_mat4x4.inl"
    "Vendor/glm/glm/detail/type_mat4x4_simd.inl"
    "Vendor/glm/glm/detail/type_quat.hpp"
    "Vendor/glm/glm/detail/type_quat.inl"
    "Vendor/glm/glm/detail/type_quat_simd.inl"
    "Vendor/glm/glm/detail/type_vec1.hpp"
    "Vendor/glm/glm/detail/type_vec1.inl"
    "Vendor/glm/glm/detail/type_vec2.hpp"
    "Vendor/glm/glm/detail/type_vec2.inl"
    "Vendor/glm/glm/detail/type_vec3.hpp"
    "Vendor/glm/glm/detail/type_vec3.inl"
    "Vendor/glm/glm/detail/type_vec4.hpp"
    "Vendor/glm/glm/detail/type_vec4.inl"
    "Vendor/glm/glm/detail/type_vec4_simd.inl"
)
source_group("Vendor\\glm\\glm\\detail" FILES ${Vendor__glm__glm__detail})

set(Vendor__glm__glm__ext
    "Vendor/glm/glm/ext/matrix_clip_space.hpp"
    "Vendor/glm/glm/ext/matrix_clip_space.inl"
    "Vendor/glm/glm/ext/matrix_common.hpp"
    "Vendor/glm/glm/ext/matrix_common.inl"
    "Vendor/glm/glm/ext/matrix_double2x2.hpp"
    "Vendor/glm/glm/ext/matrix_double2x2_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double2x3.hpp"
    "Vendor/glm/glm/ext/matrix_double2x3_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double2x4.hpp"
    "Vendor/glm/glm/ext/matrix_double2x4_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double3x2.hpp"
    "Vendor/glm/glm/ext/matrix_double3x2_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double3x3.hpp"
    "Vendor/glm/glm/ext/matrix_double3x3_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double3x4.hpp"
    "Vendor/glm/glm/ext/matrix_double3x4_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double4x2.hpp"
    "Vendor/glm/glm/ext/matrix_double4x2_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double4x3.hpp"
    "Vendor/glm/glm/ext/matrix_double4x3_precision.hpp"
    "Vendor/glm/glm/ext/matrix_double4x4.hpp"
    "Vendor/glm/glm/ext/matrix_double4x4_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float2x2.hpp"
    "Vendor/glm/glm/ext/matrix_float2x2_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float2x3.hpp"
    "Vendor/glm/glm/ext/matrix_float2x3_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float2x4.hpp"
    "Vendor/glm/glm/ext/matrix_float2x4_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float3x2.hpp"
    "Vendor/glm/glm/ext/matrix_float3x2_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float3x3.hpp"
    "Vendor/glm/glm/ext/matrix_float3x3_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float3x4.hpp"
    "Vendor/glm/glm/ext/matrix_float3x4_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float4x2.hpp"
    "Vendor/glm/glm/ext/matrix_float4x2_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float4x3.hpp"
    "Vendor/glm/glm/ext/matrix_float4x3_precision.hpp"
    "Vendor/glm/glm/ext/matrix_float4x4.hpp"
    "Vendor/glm/glm/ext/matrix_float4x4_precision.hpp"
    "Vendor/glm/glm/ext/matrix_int2x2.hpp"
    "Vendor/glm/glm/ext/matrix_int2x2_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int2x3.hpp"
    "Vendor/glm/glm/ext/matrix_int2x3_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int2x4.hpp"
    "Vendor/glm/glm/ext/matrix_int2x4_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int3x2.hpp"
    "Vendor/glm/glm/ext/matrix_int3x2_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int3x3.hpp"
    "Vendor/glm/glm/ext/matrix_int3x3_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int3x4.hpp"
    "Vendor/glm/glm/ext/matrix_int3x4_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int4x2.hpp"
    "Vendor/glm/glm/ext/matrix_int4x2_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int4x3.hpp"
    "Vendor/glm/glm/ext/matrix_int4x3_sized.hpp"
    "Vendor/glm/glm/ext/matrix_int4x4.hpp"
    "Vendor/glm/glm/ext/matrix_int4x4_sized.hpp"
    "Vendor/glm/glm/ext/matrix_projection.hpp"
    "Vendor/glm/glm/ext/matrix_projection.inl"
    "Vendor/glm/glm/ext/matrix_relational.hpp"
    "Vendor/glm/glm/ext/matrix_relational.inl"
    "Vendor/glm/glm/ext/matrix_transform.hpp"
    "Vendor/glm/glm/ext/matrix_transform.inl"
    "Vendor/glm/glm/ext/matrix_uint2x2.hpp"
    "Vendor/glm/glm/ext/matrix_uint2x2_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint2x3.hpp"
    "Vendor/glm/glm/ext/matrix_uint2x3_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint2x4.hpp"
    "Vendor/glm/glm/ext/matrix_uint2x4_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint3x2.hpp"
    "Vendor/glm/glm/ext/matrix_uint3x2_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint3x3.hpp"
    "Vendor/glm/glm/ext/matrix_uint3x3_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint3x4.hpp"
    "Vendor/glm/glm/ext/matrix_uint3x4_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint4x2.hpp"
    "Vendor/glm/glm/ext/matrix_uint4x2_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint4x3.hpp"
    "Vendor/glm/glm/ext/matrix_uint4x3_sized.hpp"
    "Vendor/glm/glm/ext/matrix_uint4x4.hpp"
    "Vendor/glm/glm/ext/matrix_uint4x4_sized.hpp"
    "Vendor/glm/glm/ext/quaternion_common.hpp"
    "Vendor/glm/glm/ext/quaternion_common.inl"
    "Vendor/glm/glm/ext/quaternion_common_simd.inl"
    "Vendor/glm/glm/ext/quaternion_double.hpp"
    "Vendor/glm/glm/ext/quaternion_double_precision.hpp"
    "Vendor/glm/glm/ext/quaternion_exponential.hpp"
    "Vendor/glm/glm/ext/quaternion_exponential.inl"
    "Vendor/glm/glm/ext/quaternion_float.hpp"
    "Vendor/glm/glm/ext/quaternion_float_precision.hpp"
    "Vendor/glm/glm/ext/quaternion_geometric.hpp"
    "Vendor/glm/glm/ext/quaternion_geometric.inl"
    "Vendor/glm/glm/ext/quaternion_relational.hpp"
    "Vendor/glm/glm/ext/quaternion_relational.inl"
    "Vendor/glm/glm/ext/quaternion_transform.hpp"
    "Vendor/glm/glm/ext/quaternion_transform.inl"
    "Vendor/glm/glm/ext/quaternion_trigonometric.hpp"
    "Vendor/glm/glm/ext/quaternion_trigonometric.inl"
    "Vendor/glm/glm/ext/scalar_common.hpp"
    "Vendor/glm/glm/ext/scalar_common.inl"
    "Vendor/glm/glm/ext/scalar_constants.hpp"
    "Vendor/glm/glm/ext/scalar_constants.inl"
    "Vendor/glm/glm/ext/scalar_int_sized.hpp"
    "Vendor/glm/glm/ext/scalar_integer.hpp"
    "Vendor/glm/glm/ext/scalar_integer.inl"
    "Vendor/glm/glm/ext/scalar_packing.hpp"
    "Vendor/glm/glm/ext/scalar_packing.inl"
    "Vendor/glm/glm/ext/scalar_relational.hpp"
    "Vendor/glm/glm/ext/scalar_relational.inl"
    "Vendor/glm/glm/ext/scalar_uint_sized.hpp"
    "Vendor/glm/glm/ext/scalar_ulp.hpp"
    "Vendor/glm/glm/ext/scalar_ulp.inl"
    "Vendor/glm/glm/ext/vector_bool1.hpp"
    "Vendor/glm/glm/ext/vector_bool1_precision.hpp"
    "Vendor/glm/glm/ext/vector_bool2.hpp"
    "Vendor/glm/glm/ext/vector_bool2_precision.hpp"
    "Vendor/glm/glm/ext/vector_bool3.hpp"
    "Vendor/glm/glm/ext/vector_bool3_precision.hpp"
    "Vendor/glm/glm/ext/vector_bool4.hpp"
    "Vendor/glm/glm/ext/vector_bool4_precision.hpp"
    "Vendor/glm/glm/ext/vector_common.hpp"
    "Vendor/glm/glm/ext/vector_common.inl"
    "Vendor/glm/glm/ext/vector_double1.hpp"
    "Vendor/glm/glm/ext/vector_double1_precision.hpp"
    "Vendor/glm/glm/ext/vector_double2.hpp"
    "Vendor/glm/glm/ext/vector_double2_precision.hpp"
    "Vendor/glm/glm/ext/vector_double3.hpp"
    "Vendor/glm/glm/ext/vector_double3_precision.hpp"
    "Vendor/glm/glm/ext/vector_double4.hpp"
    "Vendor/glm/glm/ext/vector_double4_precision.hpp"
    "Vendor/glm/glm/ext/vector_float1.hpp"
    "Vendor/glm/glm/ext/vector_float1_precision.hpp"
    "Vendor/glm/glm/ext/vector_float2.hpp"
    "Vendor/glm/glm/ext/vector_float2_precision.hpp"
    "Vendor/glm/glm/ext/vector_float3.hpp"
    "Vendor/glm/glm/ext/vector_float3_precision.hpp"
    "Vendor/glm/glm/ext/vector_float4.hpp"
    "Vendor/glm/glm/ext/vector_float4_precision.hpp"
    "Vendor/glm/glm/ext/vector_int1.hpp"
    "Vendor/glm/glm/ext/vector_int1_sized.hpp"
    "Vendor/glm/glm/ext/vector_int2.hpp"
    "Vendor/glm/glm/ext/vector_int2_sized.hpp"
    "Vendor/glm/glm/ext/vector_int3.hpp"
    "Vendor/glm/glm/ext/vector_int3_sized.hpp"
    "Vendor/glm/glm/ext/vector_int4.hpp"
    "Vendor/glm/glm/ext/vector_int4_sized.hpp"
    "Vendor/glm/glm/ext/vector_integer.hpp"
    "Vendor/glm/glm/ext/vector_integer.inl"
    "Vendor/glm/glm/ext/vector_packing.hpp"
    "Vendor/glm/glm/ext/vector_packing.inl"
    "Vendor/glm/glm/ext/vector_relational.hpp"
    "Vendor/glm/glm/ext/vector_relational.inl"
    "Vendor/glm/glm/ext/vector_uint1.hpp"
    "Vendor/glm/glm/ext/vector_uint1_sized.hpp"
    "Vendor/glm/glm/ext/vector_uint2.hpp"
    "Vendor/glm/glm/ext/vector_uint2_sized.hpp"
    "Vendor/glm/glm/ext/vector_uint3.hpp"
    "Vendor/glm/glm/ext/vector_uint3_sized.hpp"
    "Vendor/glm/glm/ext/vector_uint4.hpp"
    "Vendor/glm/glm/ext/vector_uint4_sized.hpp"
    "Vendor/glm/glm/ext/vector_ulp.hpp"
    "Vendor/glm/glm/ext/vector_ulp.inl"
)
source_group("Vendor\\glm\\glm\\ext" FILES ${Vendor__glm__glm__ext})

set(Vendor__glm__glm__gtc
    "Vendor/glm/glm/gtc/bitfield.hpp"
    "Vendor/glm/glm/gtc/bitfield.inl"
    "Vendor/glm/glm/gtc/color_space.hpp"
    "Vendor/glm/glm/gtc/color_space.inl"
    "Vendor/glm/glm/gtc/constants.hpp"
    "Vendor/glm/glm/gtc/constants.inl"
    "Vendor/glm/glm/gtc/epsilon.hpp"
    "Vendor/glm/glm/gtc/epsilon.inl"
    "Vendor/glm/glm/gtc/integer.hpp"
    "Vendor/glm/glm/gtc/integer.inl"
    "Vendor/glm/glm/gtc/matrix_access.hpp"
    "Vendor/glm/glm/gtc/matrix_access.inl"
    "Vendor/glm/glm/gtc/matrix_integer.hpp"
    "Vendor/glm/glm/gtc/matrix_inverse.hpp"
    "Vendor/glm/glm/gtc/matrix_inverse.inl"
    "Vendor/glm/glm/gtc/matrix_transform.hpp"
    "Vendor/glm/glm/gtc/matrix_transform.inl"
    "Vendor/glm/glm/gtc/noise.hpp"
    "Vendor/glm/glm/gtc/noise.inl"
    "Vendor/glm/glm/gtc/packing.hpp"
    "Vendor/glm/glm/gtc/packing.inl"
    "Vendor/glm/glm/gtc/quaternion.hpp"
    "Vendor/glm/glm/gtc/quaternion.inl"
    "Vendor/glm/glm/gtc/quaternion_simd.inl"
    "Vendor/glm/glm/gtc/random.hpp"
    "Vendor/glm/glm/gtc/random.inl"
    "Vendor/glm/glm/gtc/reciprocal.hpp"
    "Vendor/glm/glm/gtc/reciprocal.inl"
    "Vendor/glm/glm/gtc/round.hpp"
    "Vendor/glm/glm/gtc/round.inl"
    "Vendor/glm/glm/gtc/type_aligned.hpp"
    "Vendor/glm/glm/gtc/type_precision.hpp"
    "Vendor/glm/glm/gtc/type_precision.inl"
    "Vendor/glm/glm/gtc/type_ptr.hpp"
    "Vendor/glm/glm/gtc/type_ptr.inl"
    "Vendor/glm/glm/gtc/ulp.hpp"
    "Vendor/glm/glm/gtc/ulp.inl"
    "Vendor/glm/glm/gtc/vec1.hpp"
)
source_group("Vendor\\glm\\glm\\gtc" FILES ${Vendor__glm__glm__gtc})

set(Vendor__glm__glm__gtx
    "Vendor/glm/glm/gtx/associated_min_max.hpp"
    "Vendor/glm/glm/gtx/associated_min_max.inl"
    "Vendor/glm/glm/gtx/bit.hpp"
    "Vendor/glm/glm/gtx/bit.inl"
    "Vendor/glm/glm/gtx/closest_point.hpp"
    "Vendor/glm/glm/gtx/closest_point.inl"
    "Vendor/glm/glm/gtx/color_encoding.hpp"
    "Vendor/glm/glm/gtx/color_encoding.inl"
    "Vendor/glm/glm/gtx/color_space.hpp"
    "Vendor/glm/glm/gtx/color_space.inl"
    "Vendor/glm/glm/gtx/color_space_YCoCg.hpp"
    "Vendor/glm/glm/gtx/color_space_YCoCg.inl"
    "Vendor/glm/glm/gtx/common.hpp"
    "Vendor/glm/glm/gtx/common.inl"
    "Vendor/glm/glm/gtx/compatibility.hpp"
    "Vendor/glm/glm/gtx/compatibility.inl"
    "Vendor/glm/glm/gtx/component_wise.hpp"
    "Vendor/glm/glm/gtx/component_wise.inl"
    "Vendor/glm/glm/gtx/dual_quaternion.hpp"
    "Vendor/glm/glm/gtx/dual_quaternion.inl"
    "Vendor/glm/glm/gtx/easing.hpp"
    "Vendor/glm/glm/gtx/easing.inl"
    "Vendor/glm/glm/gtx/euler_angles.hpp"
    "Vendor/glm/glm/gtx/euler_angles.inl"
    "Vendor/glm/glm/gtx/extend.hpp"
    "Vendor/glm/glm/gtx/extend.inl"
    "Vendor/glm/glm/gtx/extended_min_max.hpp"
    "Vendor/glm/glm/gtx/extended_min_max.inl"
    "Vendor/glm/glm/gtx/exterior_product.hpp"
    "Vendor/glm/glm/gtx/exterior_product.inl"
    "Vendor/glm/glm/gtx/fast_exponential.hpp"
    "Vendor/glm/glm/gtx/fast_exponential.inl"
    "Vendor/glm/glm/gtx/fast_square_root.hpp"
    "Vendor/glm/glm/gtx/fast_square_root.inl"
    "Vendor/glm/glm/gtx/fast_trigonometry.hpp"
    "Vendor/glm/glm/gtx/fast_trigonometry.inl"
    "Vendor/glm/glm/gtx/float_notmalize.inl"
    "Vendor/glm/glm/gtx/functions.hpp"
    "Vendor/glm/glm/gtx/functions.inl"
    "Vendor/glm/glm/gtx/gradient_paint.hpp"
    "Vendor/glm/glm/gtx/gradient_paint.inl"
    "Vendor/glm/glm/gtx/handed_coordinate_space.hpp"
    "Vendor/glm/glm/gtx/handed_coordinate_space.inl"
    "Vendor/glm/glm/gtx/hash.hpp"
    "Vendor/glm/glm/gtx/hash.inl"
    "Vendor/glm/glm/gtx/integer.hpp"
    "Vendor/glm/glm/gtx/integer.inl"
    "Vendor/glm/glm/gtx/intersect.hpp"
    "Vendor/glm/glm/gtx/intersect.inl"
    "Vendor/glm/glm/gtx/io.hpp"
    "Vendor/glm/glm/gtx/io.inl"
    "Vendor/glm/glm/gtx/log_base.hpp"
    "Vendor/glm/glm/gtx/log_base.inl"
    "Vendor/glm/glm/gtx/matrix_cross_product.hpp"
    "Vendor/glm/glm/gtx/matrix_cross_product.inl"
    "Vendor/glm/glm/gtx/matrix_decompose.hpp"
    "Vendor/glm/glm/gtx/matrix_decompose.inl"
    "Vendor/glm/glm/gtx/matrix_factorisation.hpp"
    "Vendor/glm/glm/gtx/matrix_factorisation.inl"
    "Vendor/glm/glm/gtx/matrix_interpolation.hpp"
    "Vendor/glm/glm/gtx/matrix_interpolation.inl"
    "Vendor/glm/glm/gtx/matrix_major_storage.hpp"
    "Vendor/glm/glm/gtx/matrix_major_storage.inl"
    "Vendor/glm/glm/gtx/matrix_operation.hpp"
    "Vendor/glm/glm/gtx/matrix_operation.inl"
    "Vendor/glm/glm/gtx/matrix_query.hpp"
    "Vendor/glm/glm/gtx/matrix_query.inl"
    "Vendor/glm/glm/gtx/matrix_transform_2d.hpp"
    "Vendor/glm/glm/gtx/matrix_transform_2d.inl"
    "Vendor/glm/glm/gtx/mixed_product.hpp"
    "Vendor/glm/glm/gtx/mixed_product.inl"
    "Vendor/glm/glm/gtx/norm.hpp"
    "Vendor/glm/glm/gtx/norm.inl"
    "Vendor/glm/glm/gtx/normal.hpp"
    "Vendor/glm/glm/gtx/normal.inl"
    "Vendor/glm/glm/gtx/normalize_dot.hpp"
    "Vendor/glm/glm/gtx/normalize_dot.inl"
    "Vendor/glm/glm/gtx/number_precision.hpp"
    "Vendor/glm/glm/gtx/number_precision.inl"
    "Vendor/glm/glm/gtx/optimum_pow.hpp"
    "Vendor/glm/glm/gtx/optimum_pow.inl"
    "Vendor/glm/glm/gtx/orthonormalize.hpp"
    "Vendor/glm/glm/gtx/orthonormalize.inl"
    "Vendor/glm/glm/gtx/perpendicular.hpp"
    "Vendor/glm/glm/gtx/perpendicular.inl"
    "Vendor/glm/glm/gtx/polar_coordinates.hpp"
    "Vendor/glm/glm/gtx/polar_coordinates.inl"
    "Vendor/glm/glm/gtx/projection.hpp"
    "Vendor/glm/glm/gtx/projection.inl"
    "Vendor/glm/glm/gtx/quaternion.hpp"
    "Vendor/glm/glm/gtx/quaternion.inl"
    "Vendor/glm/glm/gtx/range.hpp"
    "Vendor/glm/glm/gtx/raw_data.hpp"
    "Vendor/glm/glm/gtx/raw_data.inl"
    "Vendor/glm/glm/gtx/rotate_normalized_axis.hpp"
    "Vendor/glm/glm/gtx/rotate_normalized_axis.inl"
    "Vendor/glm/glm/gtx/rotate_vector.hpp"
    "Vendor/glm/glm/gtx/rotate_vector.inl"
    "Vendor/glm/glm/gtx/scalar_multiplication.hpp"
    "Vendor/glm/glm/gtx/scalar_relational.hpp"
    "Vendor/glm/glm/gtx/scalar_relational.inl"
    "Vendor/glm/glm/gtx/spline.hpp"
    "Vendor/glm/glm/gtx/spline.inl"
    "Vendor/glm/glm/gtx/std_based_type.hpp"
    "Vendor/glm/glm/gtx/std_based_type.inl"
    "Vendor/glm/glm/gtx/string_cast.hpp"
    "Vendor/glm/glm/gtx/string_cast.inl"
    "Vendor/glm/glm/gtx/texture.hpp"
    "Vendor/glm/glm/gtx/texture.inl"
    "Vendor/glm/glm/gtx/transform.hpp"
    "Vendor/glm/glm/gtx/transform.inl"
    "Vendor/glm/glm/gtx/transform2.hpp"
    "Vendor/glm/glm/gtx/transform2.inl"
    "Vendor/glm/glm/gtx/type_aligned.hpp"
    "Vendor/glm/glm/gtx/type_aligned.inl"
    "Vendor/glm/glm/gtx/type_trait.hpp"
    "Vendor/glm/glm/gtx/type_trait.inl"
    "Vendor/glm/glm/gtx/vec_swizzle.hpp"
    "Vendor/glm/glm/gtx/vector_angle.hpp"
    "Vendor/glm/glm/gtx/vector_angle.inl"
    "Vendor/glm/glm/gtx/vector_query.hpp"
    "Vendor/glm/glm/gtx/vector_query.inl"
    "Vendor/glm/glm/gtx/wrap.hpp"
    "Vendor/glm/glm/gtx/wrap.inl"
)
source_group("Vendor\\glm\\glm\\gtx" FILES ${Vendor__glm__glm__gtx})

set(src
    "src/main.cpp"
)
source_group("src" FILES ${src})

set(src__Logger
    "src/Logger/Logger.cpp"
    "src/Logger/Logger.h"
)
source_group("src\\Logger" FILES ${src__Logger})

set(src__Precompiled
    "src/Precompiled/Pch.cpp"
    "src/Precompiled/Pch.h"
)
source_group("src\\Precompiled" FILES ${src__Precompiled})

set(src__Renderer
    "src/Renderer/Renderer.cpp"
    "src/Renderer/Renderer.h"
)
source_group("src\\Renderer" FILES ${src__Renderer})

set(src__Renderer__Base
    "src/Renderer/Base/VulkanBase.h"
)
source_group("src\\Renderer\\Base" FILES ${src__Renderer__Base})

set(src__Renderer__Device
    "src/Renderer/Device/LogicalDevice.cpp"
    "src/Renderer/Device/LogicalDevice.h"
    "src/Renderer/Device/PhysicalDevice.cpp"
    "src/Renderer/Device/PhysicalDevice.h"
)
source_group("src\\Renderer\\Device" FILES ${src__Renderer__Device})

set(src__Renderer__ImageViews
    "src/Renderer/ImageViews/ImageViews.cpp"
    "src/Renderer/ImageViews/ImageViews.h"
)
source_group("src\\Renderer\\ImageViews" FILES ${src__Renderer__ImageViews})

set(src__Renderer__Instances
    "src/Renderer/Instances/ApplicationInfo.h"
    "src/Renderer/Instances/Instance.cpp"
    "src/Renderer/Instances/Instance.h"
    "src/Renderer/Instances/ValidationLayers.cpp"
    "src/Renderer/Instances/ValidationLayers.h"
)
source_group("src\\Renderer\\Instances" FILES ${src__Renderer__Instances})

set(src__Renderer__Swapchain
    "src/Renderer/Swapchain/SwapChain.cpp"
    "src/Renderer/Swapchain/SwapChain.h"
)
source_group("src\\Renderer\\Swapchain" FILES ${src__Renderer__Swapchain})

set(src__Renderer__Utilities__CustomTypes
    "src/Renderer/Utilities/CustomTypes/QueueFamiliyIndices.h"
    "src/Renderer/Utilities/CustomTypes/SwapchainSupportDetails.h"
)
source_group("src\\Renderer\\Utilities\\CustomTypes" FILES ${src__Renderer__Utilities__CustomTypes})

set(src__Renderer__Utilities__FileManagment
    "src/Renderer/Utilities/FileManagment/readFile.cpp"
    "src/Renderer/Utilities/FileManagment/readFile.h"
    "src/Renderer/Utilities/FileManagment/GetSuffix.cpp"
    "src/Renderer/Utilities/FileManagment/GetSuffix.h"
)
source_group("src\\Renderer\\Utilities\\FileManagment" FILES ${src__Renderer__Utilities__FileManagment})

set(src__Renderer__Utilities__ShaderCompiler
    "src/Renderer/Utilities/ShaderCompiler/compileShader.cpp"
    "src/Renderer/Utilities/ShaderCompiler/compileShader.h"
    "src/Renderer/Utilities/ShaderCompiler/getShaderType.cpp"
    "src/Renderer/Utilities/ShaderCompiler/getShaderType.h"
)
source_group("src\\Renderer\\Utilities\\ShaderCompiler" FILES ${src__Renderer__Utilities__ShaderCompiler})

set(src__Renderer__Window
    "src/Renderer/Window/WindowMultiPlatform.cpp"
    "src/Renderer/Window/WindowMultiPlatform.h"
)
source_group("src\\Renderer\\Window" FILES ${src__Renderer__Window})

set(ALL_FILES
    ${Vendor__glm__glm}
    ${Vendor__glm__glm__detail}
    ${Vendor__glm__glm__ext}
    ${Vendor__glm__glm__gtc}
    ${Vendor__glm__glm__gtx}
    ${src}
    ${src__Logger}
    ${src__Precompiled}
    ${src__Renderer}
    ${src__Renderer__Base}
    ${src__Renderer__Device}
    ${src__Renderer__ImageViews}
    ${src__Renderer__Instances}
    ${src__Renderer__Swapchain}
    ${src__Renderer__Utilities__CustomTypes}
    ${src__Renderer__Utilities__FileManagment}
    ${src__Renderer__Utilities__ShaderCompiler}
    ${src__Renderer__Window}
)

################################################################################
# Target
################################################################################

add_executable(${PROJECT_NAME} ${ALL_FILES})

add_precompiled_header(${PROJECT_NAME} "Pch.h" "src/Precompiled/Pch.cpp")

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

set(ROOT_NAMESPACE VAR)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)

################################################################################
# Target name
################################################################################

set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUG   "VAR"
    TARGET_NAME_RELEASE "VAR"
)

################################################################################
# Output directory
################################################################################

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/../bin/Debug-windows-x86_64/VAR/"
    OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/../bin/Release-windows-x86_64/VAR/"
)

################################################################################
# MSVC runtime library
################################################################################

get_property(MSVC_RUNTIME_LIBRARY_DEFAULT TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY)
string(CONCAT "MSVC_RUNTIME_LIBRARY_STR"
    $<$<CONFIG:Debug>:
        MultiThreadedDebug
    >
    $<$<CONFIG:Release>:
        MultiThreaded
    >
    $<$<NOT:$<OR:$<CONFIG:Debug>,$<CONFIG:Release>>>:${MSVC_RUNTIME_LIBRARY_DEFAULT}>
)
set_target_properties(${PROJECT_NAME} PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY_STR})

################################################################################
# Include directories
################################################################################

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Logger;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Base;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Buffers;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Device;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Errors;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/ImageViews;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Instances;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Pipelines;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Swapchain;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Window;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/GLSL;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/SPV;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/GLSL/Compute;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/GLSL/Frag;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/GLSL/Geometry;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/GLSL/Vertex;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/SPV/Compute;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/SPV/Frag;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/SPV/Geometry;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Shaders/SPV/Vertex;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/CustomTypes;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/FileManagment;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/ShaderCompiler;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/Functions;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/Utilities/Math;"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/spdlog/include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Precompiled;"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw/include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/Vulkan/Include;"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glm"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glslang/"
)

################################################################################
# Compile definitions
################################################################################
target_compile_definitions(${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:"
        "DEBUG"
    ">"
    "$<$<CONFIG:Release>:"
        "NDEBUG"
    ">"
    "_CRT_SECURE_NO_WARNINGS;"
    "GLFW_INCLUDE_NONE;"
    "UNICODE;"
    "_UNICODE"
)

################################################################################
# Compile and link options
################################################################################

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /Od;
            /ZI
        >
        $<$<CONFIG:Release>:
            /Ox;
            /Oi;
            /GF;
            /Gy;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT}
        >
        /MP;
        /std:c++17;
        /Gm-;
        /W3;
        ${DEFAULT_CXX_EXCEPTION_HANDLING}
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:
            /DEBUG;
            /INCREMENTAL
        >
        $<$<CONFIG:Release>:
            /DEBUG:FULL;
            /OPT:REF;
            /OPT:ICF;
            /INCREMENTAL:NO
        >
        /SUBSYSTEM:CONSOLE
    )
endif()

################################################################################
# Dependencies
################################################################################

add_dependencies(${PROJECT_NAME}
    GLFW
)

# Link with other targets.
target_link_libraries(${PROJECT_NAME} PRIVATE
    GLFW
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "vulkan-1"
    "glslang"
    "SPIRV"
)
target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/Vulkan/Lib"
)

